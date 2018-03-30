<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8" media-type="text/plain"/>

    <xsl:template match="/" >
        <xsl:apply-templates select="ivy-report/dependencies/module" />
    </xsl:template>

    <xsl:template match="module">
        <xsl:apply-templates select="@*" />
        <xsl:apply-templates select="revision/@name" />
        <xsl:apply-templates select="revision/@extra-svnurl" />
        <xsl:apply-templates select="revision/@extra-svnrev" />
        <xsl:text>&#xa;</xsl:text>
    </xsl:template>

        
    <xsl:template match="@organisation">
        <xsl:value-of select="."/>
        <xsl:value-of select="substring($space-padding, 1, $max-organisation - string-length(.))"/>
        <xsl:text> # </xsl:text>
    </xsl:template>

     <xsl:template match="@name">
        <xsl:value-of select="."/>
        <xsl:apply-templates select="../revision/@branch" />
        <xsl:if test="not(../revision/@branch)" >
            <xsl:text>   </xsl:text>
        </xsl:if>
        <xsl:value-of select="substring($space-padding, 1, $max-name - string-length(concat(., ../revision/@branch)))"/>
        <xsl:text> : </xsl:text>
    </xsl:template>

     <xsl:template match="revision/@name">
        <xsl:value-of select="."/>
        <xsl:value-of select="substring($space-padding, 1, $max-revision - string-length(.))"/>
        <xsl:text> == </xsl:text>
    </xsl:template>
    
     <xsl:template match="revision/@branch">
        <xsl:text> (</xsl:text>
        <xsl:value-of select="."/>
        <xsl:text>)</xsl:text>
    </xsl:template>
    
     <xsl:template match="revision/@extra-svnurl">
        <xsl:value-of select="."/>
        <xsl:value-of select="substring($space-padding, 1, $max-url - string-length(.))"/>
        <xsl:text> @ </xsl:text>
    </xsl:template>
    
     <xsl:template match="revision/@extra-svnrev">
        <xsl:value-of select="."/>
        <xsl:value-of select="substring($space-padding, 1, $max-svnrev - string-length(.))"/>
    </xsl:template>

<!-- 
    <xsl:template match="ivy-report/dependencies/module/@*/text()">

        <xsl:variable name="padd" select="$max-org - string-length(.)" />
        Padd: <xsl:value-of select="$max-org"/> - <xsl:value-of select="string-length(.)"/> = <xsl:value-of select="$padd"/>

        :
        <xsl:value-of select="."/>
        <xsl:value-of select="substring($space-padding, 1, $padd)"/>
        <xsl:text>.</xsl:text>
    </xsl:template>
 -->
    
    <xsl:variable name="space-padding" select="'                                                                  '" />

    <xsl:variable name="max-organisation">
        <xsl:for-each select="/ivy-report/dependencies/module/@organisation">
            <xsl:sort select="string-length(.)" data-type="number" order="descending" />
            <xsl:if test="position() = 1">
                <xsl:value-of select="string-length(.)" />
            </xsl:if>
        </xsl:for-each>
    </xsl:variable>

    <xsl:variable name="max-name">
        <xsl:for-each select="/ivy-report/dependencies/module">
            <xsl:sort select="string-length(concat(@name, revision/@branch)) + 3" data-type="number" order="descending" />
            <xsl:if test="position() = 1">
                <xsl:value-of select="string-length(concat(@name, revision/@branch)) + 3" />
            </xsl:if>
        </xsl:for-each>
    </xsl:variable>
 
    <xsl:variable name="max-revision">
        <xsl:for-each select="/ivy-report/dependencies/module/revision/@name">
            <xsl:sort select="string-length(.)" data-type="number" order="descending" />
            <xsl:if test="position() = 1">
                <xsl:value-of select="string-length(.)" />
            </xsl:if>
        </xsl:for-each>
    </xsl:variable>
 
    <xsl:variable name="max-url">
        <xsl:for-each select="/ivy-report/dependencies/module/revision/@extra-svnurl">
            <xsl:sort select="string-length(.)" data-type="number" order="descending" />
            <xsl:if test="position() = 1">
                <xsl:value-of select="string-length(.)" />
            </xsl:if>
        </xsl:for-each>
    </xsl:variable>
 
    <xsl:variable name="max-svnrev">
        <xsl:for-each select="/ivy-report/dependencies/module/revision/@extra-svnrev">
            <xsl:sort select="string-length(.)" data-type="number" order="descending" />
            <xsl:if test="position() = 1">
                <xsl:value-of select="string-length(.)" />
            </xsl:if>
        </xsl:for-each>
    </xsl:variable>

</xsl:stylesheet>