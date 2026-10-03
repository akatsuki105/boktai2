	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0808F6EC @ =0x000034E4
	adds r0, r4, r1
	adds r5, r4, #0
	adds r5, #0xc0
	adds r1, r5, #0
	bl MainSprite_AdvanceAnim
	ldr r2, _0808F6F0 @ =0x00003604
	adds r6, r4, r2
	adds r0, r6, #0
	adds r1, r5, #0
	bl MainSprite_AdvanceAnim
	ldr r0, _0808F6F4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808F720
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x1d
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _0808F6F8 @ =0x0000401C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808F710
	movs r0, #8
	bl TextBox_ShowLine
	ldr r2, _0808F6FC @ =0x0000401E
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, #1
	movs r1, #0x32
	muls r1, r0, r1
	movs r0, #0
	bl TextBox_SetVarValue
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r0, _0808F700 @ =0x00001524
	adds r1, r4, r0
	ldr r0, _0808F704 @ =0x0000FFF8
	strh r0, [r1]
	ldr r2, _0808F708 @ =0x00001526
	adds r1, r4, r2
	subs r0, #0x60
	strh r0, [r1]
	ldr r1, _0808F70C @ =FUN_0808f81c
	b _0808F712
	.align 2, 0
_0808F6EC: .4byte 0x000034E4
_0808F6F0: .4byte 0x00003604
_0808F6F4: .4byte 0x030044E0
_0808F6F8: .4byte 0x0000401C
_0808F6FC: .4byte 0x0000401E
_0808F700: .4byte 0x00001524
_0808F704: .4byte 0x0000FFF8
_0808F708: .4byte 0x00001526
_0808F70C: .4byte FUN_0808f81c
_0808F710:
	ldr r1, _0808F71C @ =FUN_0808f7cc
_0808F712:
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808F76A
	.align 2, 0
_0808F71C: .4byte FUN_0808f7cc
_0808F720:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F736
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808f4ac
	b _0808F76A
_0808F736:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F76A
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _0808F76A
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _0808F770 @ =0x0000401C
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl FUN_0808f1bc
_0808F76A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F770: .4byte 0x0000401C
