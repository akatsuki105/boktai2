	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809A1E8
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #0x11
	bl FUN_08099b3c
	ldr r1, _0809A1E0 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A1E4 @ =FUN_0809a130
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	b _0809A202
	.align 2, 0
_0809A1E0: .4byte 0x00004018
_0809A1E4: .4byte FUN_0809a130
_0809A1E8:
	cmp r0, #1
	bne _0809A202
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0x13
	bl FUN_08099b3c
	ldr r1, _0809A208 @ =FUN_0809a20c
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
_0809A202:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A208: .4byte FUN_0809a20c
