	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r6, _08083EE8 @ =0x03002BF0
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083ECC
	ldr r0, _08083EEC @ =0x0000036A
	bl PlaySound_082406e0
	ldr r1, _08083EF0 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08083EF4 @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08083ECC:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08083EFC
	ldr r1, _08083EF8 @ =0x000003D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083F3C
	movs r0, #0x19
	b _08084068
	.align 2, 0
_08083EE8: .4byte 0x03002BF0
_08083EEC: .4byte 0x0000036A
_08083EF0: .4byte 0x00000472
_08083EF4: .4byte 0x00000474
_08083EF8: .4byte 0x000003D2
_08083EFC:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r5, [r0]
	adds r0, r5, #0
	subs r0, #0x18
	cmp r0, #1
	bls _08083F66
	cmp r5, #0x15
	beq _08083F66
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083F48
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	ldr r1, _08083F40 @ =0xFFFFF9FE
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #0x32
	strh r0, [r3]
	ldr r2, _08083F44 @ =0x000003D2
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
_08083F3C:
	movs r0, #0x18
	b _08084068
	.align 2, 0
_08083F40: .4byte 0xFFFFF9FE
_08083F44: .4byte 0x000003D2
_08083F48:
	cmp r5, #0x12
	beq _08083F56
	ldr r1, _08083F5C @ =0x00000474
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _08083F60
_08083F56:
	movs r0, #0x12
	b _08084068
	.align 2, 0
_08083F5C: .4byte 0x00000474
_08083F60:
	subs r0, r5, #2
	cmp r0, #1
	bhi _08083F6A
_08083F66:
	adds r0, r5, #0
	b _08084068
_08083F6A:
	cmp r5, #0x13
	bne _08083F72
	movs r0, #0x13
	b _08084068
_08083F72:
	ldr r0, _08083FD0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083FF0
	ldr r2, _08083FD4 @ =0x00000466
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08083FF6
	ldr r3, _08083FD8 @ =0x00000467
	adds r0, r4, r3
	ldrb r0, [r0]
	bl FUN_08081da4
	cmp r0, #0
	beq _08083FE0
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	beq _08083FE0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08083FE0
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083FDC @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	movs r0, #0x13
	b _08084068
	.align 2, 0
_08083FD0: .4byte 0x03002BE0
_08083FD4: .4byte 0x00000466
_08083FD8: .4byte 0x00000467
_08083FDC: .4byte 0x00000471
_08083FE0:
	ldr r0, _08083FEC @ =0x00000466
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08083FF6
	.align 2, 0
_08083FEC: .4byte 0x00000466
_08083FF0:
	ldr r2, _08084000 @ =0x00000466
	adds r0, r4, r2
	strb r1, [r0]
_08083FF6:
	cmp r5, #1
	bne _08084004
	movs r0, #1
	b _08084068
	.align 2, 0
_08084000: .4byte 0x00000466
_08084004:
	cmp r5, #0x14
	bne _0808400C
	movs r0, #0x14
	b _08084068
_0808400C:
	cmp r5, #8
	bne _08084014
	movs r0, #8
	b _08084068
_08084014:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _0808403C @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	bne _08084040
	movs r0, #0
	b _08084068
	.align 2, 0
_0808403C: .4byte 0x000004A6
_08084040:
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _08084070 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _08084074 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	movs r0, #2
_08084068:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08084070: .4byte 0x0000047E
_08084074: .4byte 0x00000471
