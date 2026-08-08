	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _080F2EDC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F2EE0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F2EE2
	.align 2, 0
_080F2EDC: .4byte 0x0000046C
_080F2EE0:
	movs r0, #0
_080F2EE2:
	cmp r0, #0
	beq _080F2F40
	ldr r1, _080F3018 @ =0x000005A4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0
	ldr r3, _080F301C @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _080F3020 @ =0x0000046B
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r5, r4
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r5, r4
	subs r1, #0x81
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _080F3024 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r0, _080F3028 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _080F302C @ =0x00000482
	adds r0, r5, r2
	strh r3, [r0]
_080F2F40:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F2F56
	b _080F31B8
_080F2F56:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _080F2F66
	b _080F31B8
_080F2F66:
	movs r2, #0x80
	lsls r2, r2, #5
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _080F303C
	movs r1, #0x97
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r1, [r0, #8]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	movs r7, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r2, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080F3030 @ =0x0000FFFE
	cmp r1, r0
	bhi _080F303C
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #0x19
	ldr r4, _080F301C @ =0x0000046D
	adds r0, r5, r4
	movs r2, #1
	strb r2, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r7, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r6, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080F3034 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _080F3038 @ =0x0000046A
	adds r0, r5, r3
	strb r7, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	b _080F31B8
	.align 2, 0
_080F3018: .4byte 0x000005A4
_080F301C: .4byte 0x0000046D
_080F3020: .4byte 0x0000046B
_080F3024: .4byte 0xFEFFFFFF
_080F3028: .4byte 0xFFFFFDFF
_080F302C: .4byte 0x00000482
_080F3030: .4byte 0x0000FFFE
_080F3034: .4byte 0x00000469
_080F3038: .4byte 0x0000046A
_080F303C:
	ldr r2, _080F3074 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0x1e
	bne _080F307C
	ldr r3, _080F3078 @ =0x000001DF
	adds r0, r5, r3
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r1, #0x80
	lsls r1, r1, #5
	mov r4, r8
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080F307C
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _080F31B8
	.align 2, 0
_080F3074: .4byte 0x00000484
_080F3078: .4byte 0x000001DF
_080F307C:
	ldr r2, _080F3104 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _080F3088
	b _080F31B4
_080F3088:
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r4, _080F3108 @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r2, [r0]
	ldr r1, _080F310C @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r5, r4
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	subs r4, #0xd0
	adds r2, r5, r4
	ldr r0, [r2]
	strh r1, [r0, #6]
	ldr r1, _080F3110 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	ldr r7, [r2]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080F3118
	ldr r0, _080F3114 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080F3142
	.align 2, 0
_080F3104: .4byte 0x00000484
_080F3108: .4byte 0x00000469
_080F310C: .4byte 0x0000046C
_080F3110: .4byte 0x000004A4
_080F3114: .4byte 0xFFFFFDFF
_080F3118:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080F3138
	cmp r0, #2
	beq _080F3134
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080F3134:
	movs r0, #1
	b _080F3144
_080F3138:
	ldr r0, _080F3158 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080F3142:
	movs r0, #0
_080F3144:
	cmp r0, #0
	bne _080F3160
	ldr r4, _080F315C @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _080F31B8
	.align 2, 0
_080F3158: .4byte 0xFFFFFDFF
_080F315C: .4byte 0x000005C4
_080F3160:
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F31B8
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _080F31A4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _080F31A8 @ =0xFFFFFDFF
	mov r4, r8
	ldrh r0, [r4]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r4]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _080F31AC @ =0x0000021E
	adds r0, r5, r2
	strh r3, [r0]
	ldr r4, _080F31B0 @ =0x00000202
	adds r0, r5, r4
	strh r3, [r0]
	b _080F31B8
	.align 2, 0
_080F31A4: .4byte 0xFEFFFFFF
_080F31A8: .4byte 0xFFFFFDFF
_080F31AC: .4byte 0x0000021E
_080F31B0: .4byte 0x00000202
_080F31B4:
	adds r0, #1
	str r0, [r1]
_080F31B8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
