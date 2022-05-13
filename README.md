## QByteArray Modular
explico detalhadamente como tratar 
a recursividade e com isso
modular para enviar 'asynchronously'
 blocos de tamanho infinito 
em uma QbyteArray via UDP.

### Considere as chaves um bloco com itens
```python
input {•••••}
```
#### Agora isolado o primeiro 'chunk'
 retiramos e fazemos o processo recursivamente

```python
await {{°°}•••}
return {•••}
```

#### Se o bloco menor do que um 'chunk' 
terminamos nossa lista infinita
```python
input {•}
await {{°}}
return {}
```
