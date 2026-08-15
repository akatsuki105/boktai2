	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r7, r2, #0
	ldrb r0, [r3]
	lsls r5, r0, #0x18
	ldrb r0, [r3, #1]
	lsls r0, r0, #0x10
	orrs r5, r0
	ldrb r0, [r3, #2]
	lsls r0, r0, #8
	orrs r5, r0
	ldrb r0, [r3, #3]
	orrs r5, r0
	lsrs r0, r5, #0x18
	movs r2, #0xf
	ands r0, r2
	str r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _08231E90
	ldr r0, _08231E8C @ =0x030046A0
	b _08231EA2
	.align 2, 0
_08231E8C: .4byte 0x030046A0
_08231E90:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _08231EA0
	ldr r0, _08231E9C @ =0x03004690
	b _08231EA2
	.align 2, 0
_08231E9C: .4byte 0x03004690
_08231EA0:
	ldr r0, _08231ECC @ =0x03004698
_08231EA2:
	ldr r6, [r0]
	ldr r0, _08231ED0 @ =0x0000FFFF
	ands r0, r5
	adds r6, r6, r0
	lsrs r0, r5, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08231ED4
	adds r0, r3, #4
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	add r2, sp, #8
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	b _08231EDA
	.align 2, 0
_08231ECC: .4byte 0x03004698
_08231ED0: .4byte 0x0000FFFF
_08231ED4:
	movs r0, #0
	str r0, [sp, #8]
	adds r4, r3, #4
_08231EDA:
	ldr r2, [sp, #8]
	adds r0, r6, #0
	adds r1, r5, #0
	adds r3, r7, #0
	bl Script_LoadPointer
	adds r0, r4, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
