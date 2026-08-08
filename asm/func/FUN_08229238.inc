	push {lr}
	ldr r2, _08229278 @ =0x00000E9C
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, _0822927C @ =0x00000E48
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _08229280 @ =0x00000E9E
	adds r1, r0, r2
	ldrh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	movs r2, #0xea
	lsls r2, r2, #4
	adds r1, r0, r2
	ldrh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _08229284 @ =0x085B0084
	adds r3, #0xca
	adds r1, r0, r3
	ldrh r1, [r1]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08229278: .4byte 0x00000E9C
_0822927C: .4byte 0x00000E48
_08229280: .4byte 0x00000E9E
_08229284: .4byte 0x085B0084
