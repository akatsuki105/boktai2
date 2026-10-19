	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x12
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x12
	movs r1, #8
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x10
	movs r1, #0xc
	movs r2, #0xc
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	bl FUN_08049f5c
	bl FUN_08049e5c
	movs r2, #1
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081da0c4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
