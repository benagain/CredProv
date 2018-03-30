# Usage notes
* `install-package MSBuildTasks`
* Add this to your `.csproj` files
```
  <Import Project="..\dependencies\scripts\Tools.Build.MsBuild\AssemblyInfo.targets" />
```
* Run `ant build`
* Add a link to the generated `Properties\AssemblyVersionInfo.cs` to the project
* Remove the duplicate `[assembly:]` attributes from `AssemblyInfo.cs`
* Add `AssemblyVersionInfo.cs` to `.gitignore`