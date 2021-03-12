# OH_MY_ZSH 세팅   
   
## - powerlevel10k 테마 적용    
    > 1. 
    >```
    >$ git clone https://github.com/romkatv/powerlevel10k git ~/.oh-my-zsh/themes/powerlevel10k
    >```
    >
    > 2. `~/.zshrc` 에서 `ZSH_THEME="powerlevel10k/powerlevel10k"` 으로 수정   
    >   
    > 3. [링크](https://github.com/romkatv/dotfiles-public/tree/master/.local/share/fonts/NerdFonts)에서 `MesloLGS NF` 폰트 설치 후 vscode `setting.json`에서 `default` 항목에 `"fontFace": "MesloLGS NF"` 추가   
    >   
    > 4. Setting wizard 실행. 다시 설정하고 싶으면 
    >   ```
    >   $ p10k configure
    >   ```   
       
## - colorls 설정 
   > `ruby` 가 안깔려있으면
   >```
   > $ sudo apt-get install ruby-full && sudo apt-get install gcc && sudo apt-get install build-essential && sudo gem install colorls
   >```
   ><br/>
   >
   > 설치 완료했으면
   >```
   > $ colorls
   >```
   >로 작동하는거 확인.
   >
   ><br/>
   >
   >`~/.zshrc` 에 ls 명령어 alias 로 colorls 설정
   >
   >```
   >alias ls='colorls --group-directories-first'
   >source $(dirname $(gem which colorls))/tab_complete.sh
   >```