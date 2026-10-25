	push {r4, r5, r6, lr}
	sub sp, #8
	mov ip, r0
	mov r6, ip
	adds r6, #0x24
	ldr r2, _08037618 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803761C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08037620 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r3, ip
	ldrb r1, [r3, #8]
	mov r3, sp
	ldrb r4, [r0]
	lsls r5, r1, #2
	ldr r1, _08037624 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08037628
	asrs r2, r0, #0xc
	b _0803762E
	.align 2, 0
_08037618: .4byte 0x030046B8
_0803761C: .4byte 0x000003FF
_08037620: .4byte 0x0203B400
_08037624: .4byte gSineTable
_08037628:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803762E:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _08037646
	asrs r0, r0, #0xc
	b _0803764C
_08037646:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803764C:
	strh r0, [r3, #4]
	adds r3, r6, #0
	adds r3, #0x20
	mov r2, ip
	adds r2, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r5, ip
	ldrh r5, [r5, #0x1c]
	adds r0, r0, r5
	strh r0, [r6, #0x20]
	ldrh r0, [r1, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
