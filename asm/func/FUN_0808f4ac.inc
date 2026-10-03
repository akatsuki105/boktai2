	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r0, _0808F504 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0808F508 @ =0x00003504
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _0808F50C @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F510 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F514 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, _0808F518 @ =0x000002C1
	bl PlaySound_082406e0
	movs r0, #3
	bl TextBox_ShowLine
	ldr r1, _0808F51C @ =FUN_0808f774
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F504: .4byte 0x000034EC
_0808F508: .4byte 0x00003504
_0808F50C: .4byte 0x0000FFE4
_0808F510: .4byte 0x00003506
_0808F514: .4byte 0x000034E4
_0808F518: .4byte 0x000002C1
_0808F51C: .4byte FUN_0808f774
