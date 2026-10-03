	push {r4, r5, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
	movs r2, #0
	ldr r4, _0804BCA0 @ =0x03005800
	ldr r0, [r4]
	adds r5, r4, #0
	ldrb r0, [r0, #8]
	cmp r2, r0
	bge _0804BC7C
	adds r3, r1, #0
_0804BC44:
	mov r0, ip
	adds r0, #0x26
	ldrb r0, [r0]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BC70
	ldr r0, [r4]
	lsls r1, r2, #5
	adds r0, r0, r1
	ldrb r0, [r0, #0x16]
	cmp r0, #3
	bhi _0804BC70
	mov r0, ip
	adds r0, #0x28
	ldrb r1, [r3]
	adds r0, r0, r1
	strb r2, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_0804BC70:
	adds r2, #1
	adds r4, r5, #0
	ldr r0, [r4]
	ldrb r0, [r0, #8]
	cmp r2, r0
	blt _0804BC44
_0804BC7C:
	mov r0, ip
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r0, #2
	adds r0, #3
	cmp r1, #0
	bge _0804BC96
	adds r2, r1, #0
_0804BC90:
	adds r2, #1
	cmp r2, #0
	blt _0804BC90
_0804BC96:
	adds r2, r1, #0
	cmp r2, #0
	bge _0804BCA6
	movs r2, #0
	b _0804BCA6
	.align 2, 0
_0804BCA0: .4byte 0x03005800
_0804BCA4:
	adds r2, #1
_0804BCA6:
	adds r1, r0, #0
	cmp r0, #8
	ble _0804BCAE
	movs r1, #8
_0804BCAE:
	cmp r2, r1
	blt _0804BCA4
	cmp r0, #7
	ble _0804BCC2
	cmp r2, r0
	bge _0804BCC2
	subs r2, r0, r2
_0804BCBC:
	subs r2, #1
	cmp r2, #0
	bne _0804BCBC
_0804BCC2:
	pop {r4, r5}
	pop {r0}
	bx r0
