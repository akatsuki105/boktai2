	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	ldr r4, _081ACC08 @ =0x0203B400
	ldr r3, _081ACC0C @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081ACC10 @ =0x000003FF
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
	mov r6, sp
	ands r4, r0
	ldr r1, _081ACC14 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081ACC18
	asrs r2, r0, #0xc
	b _081ACC1E
	.align 2, 0
_081ACC08: .4byte 0x0203B400
_081ACC0C: .4byte 0x030046B8
_081ACC10: .4byte 0x000003FF
_081ACC14: .4byte gSineTable
_081ACC18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081ACC1E:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081ACC36
	asrs r0, r0, #0xc
	b _081ACC3C
_081ACC36:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081ACC3C:
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081ACC6C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081ACC70 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x14
	mov r1, sp
	strh r0, [r1, #2]
	mov r0, ip
	movs r2, #0x1e
	movs r3, #3
	bl Entity081ee2a0_SpawnDefault
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ACC6C: .4byte 0x000003FF
_081ACC70: .4byte 0x0203B400
