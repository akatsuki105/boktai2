	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov ip, r0
	ldr r4, _081C7514 @ =0x0203B400
	ldr r3, _081C7518 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081C751C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x1f
	add r6, sp, #4
	ands r4, r0
	ldr r1, _081C7520 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081C7524
	asrs r2, r0, #0xc
	b _081C752A
	.align 2, 0
_081C7514: .4byte 0x0203B400
_081C7518: .4byte 0x030046B8
_081C751C: .4byte 0x000003FF
_081C7520: .4byte gSineTable
_081C7524:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081C752A:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081C7542
	asrs r0, r0, #0xc
	b _081C7548
_081C7542:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081C7548:
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081C757C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081C7580 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x30
	add r1, sp, #4
	strh r0, [r1, #2]
	movs r0, #3
	str r0, [sp]
	mov r0, ip
	movs r2, #0x3c
	movs r3, #3
	bl Entity081ee2a0_SpawnEx
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C757C: .4byte 0x000003FF
_081C7580: .4byte 0x0203B400
