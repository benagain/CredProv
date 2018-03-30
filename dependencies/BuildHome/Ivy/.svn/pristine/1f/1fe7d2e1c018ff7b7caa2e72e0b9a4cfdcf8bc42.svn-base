<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8" media-type="text/plain"/>
    
    <xsl:template match="/">
        <xsl:text>[</xsl:text>
        <xsl:apply-templates select="//module"/>
        <xsl:text>]</xsl:text>
    </xsl:template>
    
    <xsl:template match="//module">
    { 
        "organisation": "<xsl:value-of select="@organisation" />",
        "module": "<xsl:value-of select="@name" />",
        "branch": "<xsl:value-of select="revision/@branch" />",
        "version": "<xsl:value-of select="revision/@name" />",
        "svn": { 
            "url": "<xsl:value-of select="revision/@extra-svnurl" />",
            "revision": "<xsl:value-of select="revision/@extra-svnrev" />"
        }
    }<xsl:if test="position() != last()">,</xsl:if>
    </xsl:template>
</xsl:stylesheet>