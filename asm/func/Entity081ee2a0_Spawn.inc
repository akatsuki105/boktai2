	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r7, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r0, _081EE0D8 @ =0x030001CC
	ldr r6, [r0]
	cmp r6, #0
	bne _081EE0C6
	bl Entity081ee2a0_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _081EE0D2
_081EE0C6:
	adds r0, r6, #0
	bl Entity081ee2a0_AllocElem
	adds r5, r0, #0
	cmp r5, #0
	bne _081EE0DC
_081EE0D2:
	movs r0, #0
	b _081EE1AA
	.align 2, 0
_081EE0D8: .4byte 0x030001CC
_081EE0DC:
	adds r2, r5, #0
	adds r2, #0x32
	movs r0, #0
	movs r1, #1
	strb r1, [r2]
	movs r2, #0
	strh r0, [r5, #0x30]
	adds r0, r5, #0
	adds r0, #0x34
	strb r1, [r0]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r5, #0x28]
	str r1, [r5, #0x2c]
	mov r0, r8
	strh r0, [r5, #0x38]
	adds r1, r5, #0
	adds r1, #0x35
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x36
	strb r2, [r0]
	cmp r4, #7
	bhi _081EE158
	lsls r0, r4, #2
	ldr r1, _081EE118 @ =_081EE11C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081EE118: .4byte _081EE11C
_081EE11C: @ jump table
	.4byte _081EE158 @ case 0
	.4byte _081EE13C @ case 1
	.4byte _081EE140 @ case 2
	.4byte _081EE144 @ case 3
	.4byte _081EE148 @ case 4
	.4byte _081EE14C @ case 5
	.4byte _081EE150 @ case 6
	.4byte _081EE154 @ case 7
_081EE13C:
	movs r1, #1
	b _081EE15A
_081EE140:
	movs r1, #2
	b _081EE15A
_081EE144:
	movs r1, #3
	b _081EE15A
_081EE148:
	movs r1, #4
	b _081EE15A
_081EE14C:
	movs r1, #5
	b _081EE15A
_081EE150:
	movs r1, #6
	b _081EE15A
_081EE154:
	movs r1, #7
	b _081EE15A
_081EE158:
	movs r1, #0
_081EE15A:
	adds r2, r5, #0
	adds r2, #0x37
	movs r0, #0
	strb r0, [r2]
	lsls r0, r1, #1
	adds r4, r5, #0
	adds r4, #0x3c
	strb r0, [r4]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r1, [r6, #0x18]
	adds r0, r5, #0
	movs r2, #0
	bl Particle_Add
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r6, #0x18]
	ldrb r2, [r4]
	adds r0, r5, #0
	bl Particle_SetPose
	adds r0, r5, #0
	movs r1, #1
	bl Particle_SetPltt
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r0, [r5, #0xf]
	adds r0, r5, #0
_081EE1AA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
