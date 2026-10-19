	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r7, #0
_081DA46E:
	cmp r7, #4
	bls _081DA474
	b _081DA5C0
_081DA474:
	lsls r0, r7, #2
	ldr r1, _081DA480 @ =_081DA484
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA480: .4byte _081DA484
_081DA484: @ jump table
	.4byte _081DA498 @ case 0
	.4byte _081DA4CC @ case 1
	.4byte _081DA50C @ case 2
	.4byte _081DA594 @ case 3
	.4byte _081DA5AC @ case 4
_081DA498:
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #5
	adds r1, r6, r1
	ldr r3, _081DA4C4 @ =0x085AE16C
	ldr r0, _081DA4C8 @ =0x0000029D
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r2, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r2, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r3, #4
	adds r0, r0, r3
	ldr r0, [r0]
	adds r1, #0x42
	strh r0, [r1]
	b _081DA5C0
	.align 2, 0
_081DA4C4: .4byte 0x085AE16C
_081DA4C8: .4byte 0x0000029D
_081DA4CC:
	ldr r1, _081DA4FC @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA4E0
	ldr r2, _081DA500 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4E0:
	cmp r1, #2
	bne _081DA4EE
	ldr r1, _081DA504 @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4EE:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA508 @ =0x085AE184
	b _081DA55A
	.align 2, 0
_081DA4FC: .4byte 0x0000029D
_081DA500: .4byte 0x00000289
_081DA504: .4byte 0x0000028B
_081DA508: .4byte 0x085AE184
_081DA50C:
	ldr r1, _081DA544 @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA520
	ldr r2, _081DA548 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA520:
	cmp r1, #2
	bne _081DA550
	ldr r1, _081DA54C @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _081DA550
_081DA52E:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA544: .4byte 0x0000029D
_081DA548: .4byte 0x00000289
_081DA54C: .4byte 0x0000028B
_081DA550:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA58C @ =0x085AE19C
_081DA55A:
	ldr r0, _081DA590 @ =0x0000029D
	adds r5, r6, r0
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x42
	strh r0, [r4]
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA58C: .4byte 0x085AE19C
_081DA590: .4byte 0x0000029D
_081DA594:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r2, r0, #0
	adds r2, #0x40
	movs r1, #0x48
	strh r1, [r2]
	adds r0, #0x42
	movs r1, #0x60
	strh r1, [r0]
	b _081DA5C0
_081DA5AC:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	strh r2, [r1]
	adds r0, #0x42
	strh r2, [r0]
_081DA5C0:
	adds r7, #1
	cmp r7, #4
	bgt _081DA5C8
	b _081DA46E
_081DA5C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
