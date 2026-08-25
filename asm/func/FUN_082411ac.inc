	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #3
	bl FUN_08243648
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0824100c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0824120C @ =0x03004698
	ldr r1, [r1]
	adds r2, r4, #0
	bl FUN_082439f0
	cmp r0, #0
	blt _0824121C
	bl FUN_08241078
	bl FUN_08243648
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0824100c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08241210 @ =0x030046A0
	ldr r1, [r5]
	adds r2, r4, #0
	bl FUN_082439f0
	cmp r0, #0
	blt _0824121C
	ldr r0, [r5]
	ldr r1, _08241214 @ =gScriptDirectoryBuildTime
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne _0824121C
	ldr r1, _08241218 @ =0x030047B4
	movs r0, #1
	str r0, [r1]
	b _0824121E
	.align 2, 0
_0824120C: .4byte 0x03004698
_08241210: .4byte 0x030046A0
_08241214: .4byte gScriptDirectoryBuildTime
_08241218: .4byte 0x030047B4
_0824121C:
	movs r0, #0
_0824121E:
	pop {r4, r5}
	pop {r1}
	bx r1
