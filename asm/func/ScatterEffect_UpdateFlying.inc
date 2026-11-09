	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	movs r0, #0
	mov sb, r0
	mov r8, r0
	ldrb r1, [r5, #1]
	cmp sb, r1
	bge _08014132
	adds r4, r5, #4
	adds r6, r5, #0
	adds r6, #0x14
_080140B4:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08014124
	ldrb r0, [r5, #2]
	cmp r0, #0x14
	bhi _080140C4
	ldr r2, [r3, #0x1c]
	b _080140C6
_080140C4:
	ldr r2, [r3, #0x20]
_080140C6:
	ldrh r0, [r4, #8]
	ldrh r7, [r4, #0x28]
	adds r0, r0, r7
	movs r1, #0
	mov ip, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0xc]
	ldrh r7, [r4, #0x2c]
	adds r0, r0, r7
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #0xa]
	ldrh r7, [r4, #6]
	adds r1, r0, r7
	strh r1, [r4, #6]
	subs r0, #1
	strh r0, [r4, #0xa]
	strh r1, [r4, #0x2a]
	ldr r1, _0801411C @ =0x085AA850
	ldrb r0, [r5, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrb r0, [r5, #3]
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #2]
	adds r1, r0, #1
	strb r1, [r4, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #3]
	cmp r0, r1
	blo _08014120
	mov r7, ip
	strb r7, [r4]
	adds r0, r6, #0
	str r3, [sp]
	bl Particle_Remove
	ldr r3, [sp]
	b _08014124
	.align 2, 0
_0801411C: .4byte 0x085AA850
_08014120:
	movs r0, #1
	add sb, r0
_08014124:
	adds r4, #0x38
	adds r6, #0x38
	movs r1, #1
	add r8, r1
	ldrb r7, [r5, #1]
	cmp r8, r7
	blt _080140B4
_08014132:
	mov r0, sb
	cmp r0, #0
	bne _0801413A
	strb r0, [r5]
_0801413A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
