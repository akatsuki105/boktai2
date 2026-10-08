	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809A260 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
	ldr r0, _0809A264 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0809A25A
	movs r0, #0x11
	bl FUN_08099b3c
	ldr r1, _0809A268 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A26C @ =FUN_0809a130
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	ldr r0, _0809A270 @ =0x0000400C
	adds r1, r4, r0
	movs r0, #0x1e
	strb r0, [r1]
	bl FUN_0823d22c
_0809A25A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A260: .4byte 0x030047B8
_0809A264: .4byte 0x000009EE
_0809A268: .4byte 0x00004018
_0809A26C: .4byte FUN_0809a130
_0809A270: .4byte 0x0000400C
