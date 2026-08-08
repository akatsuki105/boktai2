	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, _08231A68 @ =0x03000748
	ldrb r1, [r4, #3]
	lsls r1, r1, #0x18
	ldrb r0, [r4, #2]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r4]
	orrs r1, r0
	ldr r0, _08231A6C @ =0x03004594
	str r1, [r0]
	adds r4, #4
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08231858
	str r4, [r5]
	ldr r1, [sp]
	str r1, [r5, #4]
	ldr r4, _08231A70 @ =0x03000758
	str r0, [r4]
	adds r3, r0, #4
	ldrb r2, [r3, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r3, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r3, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0, #4]
	orrs r2, r1
	adds r2, r0, r2
	str r2, [r4, #4]
	adds r3, #4
	ldrb r2, [r3, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r3, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r3, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0, #8]
	orrs r2, r1
	adds r2, r0, r2
	str r2, [r4, #8]
	adds r3, #4
	ldrb r2, [r3, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r3, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r3, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0, #0xc]
	orrs r2, r1
	adds r2, r0, r2
	str r2, [r4, #0xc]
	ldrb r2, [r0, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0]
	orrs r2, r1
	adds r0, r0, r2
	adds r1, r0, #4
	str r1, [r5, #8]
	ldrb r2, [r0, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0]
	orrs r2, r1
	adds r2, r2, r0
	adds r2, #8
	str r2, [r5, #0xc]
	movs r0, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08231A68: .4byte 0x03000748
_08231A6C: .4byte 0x03004594
_08231A70: .4byte 0x03000758
