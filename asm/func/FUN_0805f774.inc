	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x30]
	mov sl, r0
	movs r1, #0
	mov sb, r1
	ldrb r2, [r6, #7]
	cmp sb, r2
	bge _0805F7AC
	adds r5, r6, #0
	adds r5, #0x14
_0805F79A:
	adds r0, r5, #0
	bl Particle_Remove
	adds r5, #0x28
	movs r3, #1
	add sb, r3
	ldrb r0, [r6, #7]
	cmp sb, r0
	blt _0805F79A
_0805F7AC:
	movs r0, #0
	strb r0, [r6, #7]
	mov r1, sl
	ldrh r0, [r1, #2]
	strh r0, [r6, #8]
	ldrh r0, [r1, #2]
	adds r0, #6
	strh r0, [r6, #0xa]
	ldr r1, _0805F8C4 @ =0x0000270F
	adds r0, r6, #0
	adds r0, #0x8c
	movs r2, #0x64
	adds r2, r2, r6
	mov sb, r2
	movs r3, #0x3c
	adds r3, r3, r6
	mov sl, r3
	adds r2, r6, #0
	adds r2, #0x14
	str r2, [sp, #8]
	cmp r4, r1
	bls _0805F7E0
	ldr r2, _0805F8C8 @ =0xFFFFD8F0
_0805F7DA:
	adds r4, r4, r2
	cmp r4, r1
	bhi _0805F7DA
_0805F7E0:
	movs r5, #0
	ldr r1, _0805F8CC @ =0x000003E7
	cmp r4, r1
	bls _0805F7F2
	ldr r2, _0805F8D0 @ =0xFFFFFC18
_0805F7EA:
	adds r5, #1
	adds r4, r4, r2
	cmp r4, r1
	bhi _0805F7EA
_0805F7F2:
	ldr r1, [r7, #0x1c]
	mov r3, r8
	adds r2, r3, r5
	bl Particle_SetPose
	cmp r5, #0
	ble _0805F804
	movs r0, #4
	strb r0, [r6, #7]
_0805F804:
	movs r5, #0
	cmp r4, #0x63
	bls _0805F812
_0805F80A:
	adds r5, #1
	subs r4, #0x64
	cmp r4, #0x63
	bhi _0805F80A
_0805F812:
	ldr r1, [r7, #0x1c]
	mov r0, r8
	adds r2, r0, r5
	mov r0, sb
	bl Particle_SetPose
	ldrb r0, [r6, #7]
	cmp r0, #0
	bne _0805F82C
	cmp r5, #0
	ble _0805F82C
	movs r0, #3
	strb r0, [r6, #7]
_0805F82C:
	movs r5, #0
	cmp r4, #9
	bls _0805F83A
_0805F832:
	adds r5, #1
	subs r4, #0xa
	cmp r4, #9
	bhi _0805F832
_0805F83A:
	ldr r1, [r7, #0x1c]
	mov r3, r8
	adds r2, r3, r5
	mov r0, sl
	bl Particle_SetPose
	ldrb r0, [r6, #7]
	cmp r0, #0
	bne _0805F854
	cmp r5, #0
	ble _0805F854
	movs r0, #2
	strb r0, [r6, #7]
_0805F854:
	movs r5, #0
	ldr r1, [r7, #0x1c]
	cmp r4, #0
	beq _0805F864
_0805F85C:
	adds r5, #1
	subs r4, #1
	cmp r4, #0
	bne _0805F85C
_0805F864:
	ldr r0, [sp, #8]
	mov r7, r8
	adds r2, r7, r5
	bl Particle_SetPose
	ldrb r1, [r6, #7]
	cmp r1, #0
	bne _0805F878
	movs r1, #1
	strb r1, [r6, #7]
_0805F878:
	ldr r1, [sp, #8]
	mov r8, r1
	movs r2, #0
	mov sb, r2
	ldrb r3, [r6, #7]
	cmp sb, r3
	blt _0805F888
	b _0805F996
_0805F888:
	ldr r7, _0805F8D4 @ =0x030047C8
	mov sl, r7
	movs r0, #0
	str r0, [sp, #0xc]
_0805F890:
	ldrb r0, [r6, #5]
	lsls r0, r0, #4
	mov r2, sb
	lsls r1, r2, #5
	adds r5, r0, r1
	cmp r5, #0x80
	ble _0805F8A0
	movs r5, #0x80
_0805F8A0:
	mov r4, sp
	adds r7, r6, #0
	adds r7, #0xc
	ldrh r0, [r6, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805F8D8
	asrs r0, r0, #8
	b _0805F8DE
	.align 2, 0
_0805F8C4: .4byte 0x0000270F
_0805F8C8: .4byte 0xFFFFD8F0
_0805F8CC: .4byte 0x000003E7
_0805F8D0: .4byte 0xFFFFFC18
_0805F8D4: .4byte 0x030047C8
_0805F8D8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805F8DE:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805F8F0
	asrs r0, r0, #8
	b _0805F8F6
_0805F8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805F8F6:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0805F90A
	asrs r0, r0, #8
	b _0805F910
_0805F90A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805F910:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r4]
	mov r7, sl
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r7, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r7, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, [sp, #0xc]
	subs r1, r1, r0
	ldr r2, _0805F960 @ =0x085ABA88
	ldrb r0, [r6, #7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	subs r1, r1, r0
	mov r2, r8
	strh r1, [r2, #0x18]
	ldr r1, _0805F964 @ =gSineTable
	movs r0, #0xff
	ands r5, r0
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805F968
	asrs r1, r0, #0xc
	b _0805F96E
	.align 2, 0
_0805F960: .4byte 0x085ABA88
_0805F964: .4byte gSineTable
_0805F968:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805F96E:
	mov r0, sp
	ldrh r0, [r0, #2]
	subs r0, r0, r1
	mov r7, r8
	strh r0, [r7, #0x1a]
	mov r0, r8
	movs r1, #0
	bl Particle_AddToDrawList
	ldr r1, [sp, #0xc]
	adds r1, #5
	str r1, [sp, #0xc]
	movs r2, #1
	add sb, r2
	movs r3, #0x28
	add r8, r3
	ldrb r7, [r6, #7]
	cmp sb, r7
	bge _0805F996
	b _0805F890
_0805F996:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
