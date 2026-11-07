	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r3, _08143024 @ =0x0000046D
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143028
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814302A
	.align 2, 0
_08143024: .4byte 0x0000046D
_08143028:
	movs r0, #0
_0814302A:
	cmp r0, #0
	beq _08143038
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _0814308A
_08143038:
	movs r1, #4
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814304C
	movs r0, #1
	b _0814304E
_0814304C:
	movs r0, #0
_0814304E:
	cmp r0, #0
	bne _0814308A
	adds r0, r2, #0
	movs r1, #0x5a
	bl Mod
	cmp r0, #0
	bne _08143078
	adds r0, r4, #0
	movs r1, #0x10
	bl Enemy_PlayAnim
	ldr r0, _08143074 @ =0x00000671
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #0x28
	strb r0, [r1]
	b _0814308A
	.align 2, 0
_08143074: .4byte 0x00000671
_08143078:
	ldr r1, _08143090 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814308A
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
_0814308A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08143090: .4byte 0x0000046E
