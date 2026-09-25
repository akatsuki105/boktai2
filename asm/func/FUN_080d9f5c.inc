	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080D9F88 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9F8C
	bl Entity080da848_Create
	mov sl, r0
	cmp r0, #0
	bne _080D9F8E
_080D9F84:
	movs r0, #0
	b _080DA100
	.align 2, 0
_080D9F88: .4byte 0x0300015C
_080D9F8C:
	mov sl, r0
_080D9F8E:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _080D9F84
	mov r0, sl
	bl FUN_080d99c4
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	str r1, [sp, #0x20]
	cmp r7, #0
	beq _080D9F84
	movs r2, #0x2c
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	strb r5, [r2]
	movs r3, #0x2f
	adds r3, r3, r7
	mov r8, r3
	ldr r0, [sp, #0x48]
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	adds r5, r7, #0
	adds r5, #0x3a
	movs r6, #2
	strb r6, [r5]
	strh r4, [r7, #0x30]
	mov r0, sp
	ldrh r0, [r0, #0x18]
	strh r0, [r7, #0x24]
	strh r4, [r7, #0x26]
	mov r1, sp
	ldrh r1, [r1, #0x1c]
	strh r1, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080d8644
	strh r4, [r7, #0x3c]
	strh r4, [r7, #8]
	strh r4, [r7, #6]
	strh r4, [r7, #4]
	adds r1, r7, #0
	adds r1, #0x3b
	strb r6, [r1]
	str r4, [r7, #0x58]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, [sp, #0x4c]
	str r3, [r0]
	str r4, [sp, #0x10]
	str r4, [sp, #0xc]
	ldr r6, [sp, #0x20]
	ldrb r0, [r5]
	mov r2, sb
	str r2, [sp, #0x24]
	mov sb, r5
	adds r4, r1, #0
	cmp r0, #2
	beq _080DA016
	cmp r0, #3
	beq _080DA01C
	movs r1, #0
	b _080DA020
_080DA016:
	mov r3, sl
	ldr r1, [r3, #0x58]
	b _080DA020
_080DA01C:
	mov r0, sl
	ldr r1, [r0, #0x58]
_080DA020:
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822d9f0
	ldrb r0, [r4]
	mov r2, r8
	ldrb r1, [r2]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r5, r7, r3
	ldr r2, [r5]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	add r4, sp, #0x10
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	adds r0, r6, #0
	bl Particle_SetOffset
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080DA064
	ldr r0, [r5]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA074
_080DA064:
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _080DA0A0 @ =0x05000002
	bl CpuSet
_080DA074:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	movs r0, #0x7f
	strb r0, [r6, #0x10]
	strb r1, [r6, #0xf]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0xff
	strh r0, [r1]
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #5
	bhi _080DA0CC
	lsls r0, r0, #2
	ldr r1, _080DA0A4 @ =_080DA0A8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA0A0: .4byte 0x05000002
_080DA0A4: .4byte _080DA0A8
_080DA0A8: @ jump table
	.4byte _080DA0C0 @ case 0
	.4byte _080DA0CC @ case 1
	.4byte _080DA0C6 @ case 2
	.4byte _080DA0C6 @ case 3
	.4byte _080DA0CC @ case 4
	.4byte _080DA0CC @ case 5
_080DA0C0:
	mov r0, sl
	ldr r1, [r0, #0x50]
	b _080DA0CE
_080DA0C6:
	mov r2, sl
	ldr r1, [r2, #0x54]
	b _080DA0CE
_080DA0CC:
	movs r1, #0
_080DA0CE:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r3, [sp, #0x24]
	ldrb r2, [r3]
	movs r4, #0
	str r4, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [sp, #0x14]
	str r0, [r7]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, [sp, #0x20]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	adds r1, r7, #0
	adds r1, #0x38
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, r7, #0
_080DA100:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
