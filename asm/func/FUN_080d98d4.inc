	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9952
	adds r1, r6, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080D98FA
	ldr r0, [r2, #0x30]
	ldr r1, [r2, #0x34]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	b _080D9952
_080D98FA:
	adds r4, r6, #0
	adds r4, #0x3b
	ldrb r0, [r4]
	ldrb r1, [r1]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r6, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080D9946
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x38
	adds r4, #0x4d
_080D9926:
	ldrb r0, [r7]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D993C
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	adds r0, r4, #0
	bl Particle_SetOffset
_080D993C:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9926
	b _080D9952
_080D9946:
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r6, #0x1c]
	strh r1, [r6, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r6, #0x20]
_080D9952:
	ldr r0, _080D9970 @ =0x085AD2EC
	adds r1, r6, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r6, #0
	bl _call_via_r1
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D9970: .4byte 0x085AD2EC
