	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808F850 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	adds r0, r4, #0
	bl FUN_0808b760
	adds r5, r0, #0
	cmp r5, #0
	bne _0808F858
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #7
	bl TextBox_ShowLine
	ldr r1, _0808F854 @ =FUN_0808f670
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808F8A2
	.align 2, 0
_0808F850: .4byte 0x000034E4
_0808F854: .4byte FUN_0808f670
_0808F858:
	cmp r5, #1
	bne _0808F8A2
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r3, _0808F8A8 @ =0x030046A0
	ldr r2, [r3]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _0808F8AC @ =0x0000401E
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	movs r1, #0x32
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0808F8B0 @ =0x0000270F
	cmp r0, r1
	ble _0808F88E
	ldr r0, [r3]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r0, r2
	str r1, [r0]
_0808F88E:
	ldr r1, _0808F8B4 @ =0x00003FB0
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0808F8B8 @ =0x00003FB1
	adds r1, r4, r2
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808f3f8
_0808F8A2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F8A8: .4byte 0x030046A0
_0808F8AC: .4byte 0x0000401E
_0808F8B0: .4byte 0x0000270F
_0808F8B4: .4byte 0x00003FB0
_0808F8B8: .4byte 0x00003FB1
