	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08099F50 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08099F4A
	movs r0, #5
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _08099F54 @ =FUN_08099e2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
_08099F4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099F50: .4byte 0x000009EE
_08099F54: .4byte FUN_08099e2c
