	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r0, _0808F484 @ =0x000034EC
	adds r1, r4, r0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808F488 @ =0x00003504
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _0808F48C @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F490 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F494 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, _0808F498 @ =0x0000354C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F45C
	ldr r0, _0808F49C @ =0x000035AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
_0808F45C:
	ldr r0, _0808F4A0 @ =0x0000360C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808F4A4 @ =0x000002C1
	bl PlaySound_082406e0
	movs r0, #3
	bl TextBox_ShowLine
	ldr r1, _0808F4A8 @ =FUN_0808f8bc
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F484: .4byte 0x000034EC
_0808F488: .4byte 0x00003504
_0808F48C: .4byte 0x0000FFE4
_0808F490: .4byte 0x00003506
_0808F494: .4byte 0x000034E4
_0808F498: .4byte 0x0000354C
_0808F49C: .4byte 0x000035AC
_0808F4A0: .4byte 0x0000360C
_0808F4A4: .4byte 0x000002C1
_0808F4A8: .4byte FUN_0808f8bc
