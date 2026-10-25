	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r7, _080C3DA0 @ =0x030046B8
	ldr r0, _080C3DA4 @ =0xFFFF0000
	mov r8, r0
	add r5, sp, #0x10
	movs r6, #4
_080C3D28:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080C3DA8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080C3DAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	asrs r2, r2, #3
	movs r0, #0xff
	ands r2, r0
	movs r0, #0x9b
	lsls r0, r0, #2
	adds r3, r4, r0
	ldr r1, _080C3DB0 @ =0x0000026E
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r2, #0x80
	adds r1, r2, r1
	lsls r1, r1, #0x10
	ldrh r0, [r3]
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl EmitSmoke
	subs r6, #1
	cmp r6, #0
	bge _080C3D28
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3DA0: .4byte 0x030046B8
_080C3DA4: .4byte 0xFFFF0000
_080C3DA8: .4byte 0x000003FF
_080C3DAC: .4byte 0x0203B400
_080C3DB0: .4byte 0x0000026E
