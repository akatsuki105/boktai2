	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _08140E94
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r3, #0xff
	mov r8, r3
	ands r0, r3
	lsrs r2, r0, #6
	adds r2, #2
	ldr r6, _08140E4C @ =0x0203B400
	ldr r5, _08140E50 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _08140E54 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	lsls r2, r2, #0x1e
	asrs r2, r2, #0x18
	subs r2, #0x20
	movs r0, #0x3f
	ands r3, r0
	adds r2, r2, r3
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	add r4, sp, #4
	adds r5, r0, #1
	ldr r1, _08140E58 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08140E5C
	asrs r3, r0, #0xc
	b _08140E62
	.align 2, 0
_08140E4C: .4byte 0x0203B400
_08140E50: .4byte 0x030046B8
_08140E54: .4byte 0x000003FF
_08140E58: .4byte gSineTable
_08140E5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08140E62:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08140E7A
	asrs r0, r0, #0xc
	b _08140E80
_08140E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08140E80:
	strh r0, [r4, #4]
	adds r0, r7, #0
	adds r0, #8
	movs r1, #1
	str r1, [sp]
	add r1, sp, #4
	movs r2, #0x28
	movs r3, #2
	bl Entity081fa164_SpawnEx
_08140E94:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
