	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809b348
	cmp r0, #0
	bne _0809B3C0
	movs r0, #0
	b _0809B406
_0809B3C0:
	movs r2, #4
	ldr r1, _0809B40C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809B410 @ =0x03004460
	ldr r1, [r0]
	ldr r2, _0809B414 @ =0x000009B2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B418 @ =0x03004494
	ldrh r1, [r0]
	ldr r2, _0809B41C @ =0x00003B1C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B420 @ =0x03004454
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B424 @ =0x03004464
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B428 @ =0x03004490
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, _0809B42C @ =FUN_0809aaf4
	adds r0, r4, #0
	bl FUN_0808a33c
	movs r0, #1
_0809B406:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809B40C: .4byte 0x030044BC
_0809B410: .4byte 0x03004460
_0809B414: .4byte 0x000009B2
_0809B418: .4byte 0x03004494
_0809B41C: .4byte 0x00003B1C
_0809B420: .4byte 0x03004454
_0809B424: .4byte 0x03004464
_0809B428: .4byte 0x03004490
_0809B42C: .4byte FUN_0809aaf4
