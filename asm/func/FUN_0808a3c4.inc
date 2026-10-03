	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r1, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x24]
	movs r4, #0
	str r4, [sp, #0xc]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	adds r2, r5, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Video_SetBGLayer
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, _0808A418 @ =0x030043F0
	ldr r2, _0808A41C @ =0x04000018
	adds r0, r7, #0
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808A418: .4byte 0x030043F0
_0808A41C: .4byte 0x04000018
