	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl FUN_080ef840
	ldr r0, _080EDB34 @ =0x03002C60
	ldr r5, [r0]
	ldr r4, [r5, #4]
	cmp r4, #0
	beq _080EDB24
	ldr r0, _080EDB38 @ =0x0000A007
	mov sl, r0
	ldr r1, _080EDB3C @ =FUN_080e48d0
	mov sb, r1
	movs r2, #0x10
	mov r8, r2
	movs r6, #1
	movs r7, #0
_080EDAA4:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EDB1C
	ldr r1, _080EDB40 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080EDAC6
	cmp r0, #1
	beq _080EDAC6
	cmp r0, #3
	beq _080EDAC6
	cmp r0, #0xa
	bne _080EDB1C
_080EDAC6:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r1, [r0]
	mov r0, sl
	ands r1, r0
	cmp r1, #0
	bne _080EDB1C
	ldr r2, _080EDB44 @ =0x0000046D
	adds r0, r4, r2
	strb r6, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #0xe8
	adds r0, r4, r2
	mov r2, r8
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	mov r2, sb
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r7, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r7, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _080EDB48 @ =0x0000046C
	adds r0, r4, r1
	strb r6, [r0]
_080EDB1C:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	cmp r4, #0
	bne _080EDAA4
_080EDB24:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EDB34: .4byte 0x03002C60
_080EDB38: .4byte 0x0000A007
_080EDB3C: .4byte FUN_080e48d0
_080EDB40: .4byte 0x000001DF
_080EDB44: .4byte 0x0000046D
_080EDB48: .4byte 0x0000046C
