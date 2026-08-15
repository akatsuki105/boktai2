	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	lsls r3, r0, #0x18
	ldrb r0, [r4, #1]
	lsls r0, r0, #0x10
	orrs r3, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r3, r0
	ldrb r0, [r4, #3]
	orrs r3, r0
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r3
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _08232118
	ldr r0, _08232114 @ =0x030046A0
	b _0823212A
	.align 2, 0
_08232114: .4byte 0x030046A0
_08232118:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _08232128
	ldr r0, _08232124 @ =0x03004690
	b _0823212A
	.align 2, 0
_08232124: .4byte 0x03004690
_08232128:
	ldr r0, _08232158 @ =0x03004698
_0823212A:
	ldr r2, [r0]
	ldr r0, _0823215C @ =0x0000FFFF
	ands r0, r3
	adds r2, r2, r0
	lsrs r0, r3, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232140
	ldrh r0, [r4, #6]
	adds r5, r5, r0
_08232140:
	adds r0, r2, #0
	adds r1, r3, #0
	adds r2, r5, #0
	mov r3, sp
	bl Script_LoadPointer
	ldr r0, [sp]
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08232158: .4byte 0x03004698
_0823215C: .4byte 0x0000FFFF
