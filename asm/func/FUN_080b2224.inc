	push {r4, lr}
	sub sp, #8
	ldr r4, _080B2268 @ =0x03002C58
	ldr r0, [r4]
	cmp r0, #0
	beq _080B22E0
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r4]
	ldrh r2, [r0, #0x1a]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _080B226C @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080B2280
	ldr r1, _080B2270 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _080B2274
	mov r0, sp
	movs r1, #0
	movs r2, #1
	bl FUN_0823206c
	b _080B228A
	.align 2, 0
_080B2268: .4byte 0x03002C58
_080B226C: .4byte 0x03002C00
_080B2270: .4byte 0x000001F5
_080B2274:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	b _080B228A
_080B2280:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
_080B228A:
	movs r4, #0
_080B228C:
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _080B22B8 @ =0x03002C58
	ldr r0, [r0]
	lsls r1, r4, #2
	ldr r2, _080B22BC @ =0x00000BE8
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B22AC
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080B22C0
_080B22AC:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	b _080B22DA
	.align 2, 0
_080B22B8: .4byte 0x03002C58
_080B22BC: .4byte 0x00000BE8
_080B22C0:
	cmp r0, #4
	bne _080B22D0
	mov r0, sp
	movs r1, #0
	movs r2, #4
	bl FUN_0823206c
	b _080B22DA
_080B22D0:
	mov r0, sp
	movs r1, #0
	movs r2, #2
	bl FUN_0823206c
_080B22DA:
	adds r4, #1
	cmp r4, #3
	ble _080B228C
_080B22E0:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
