	push {r4, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0x9c
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
