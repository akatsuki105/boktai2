	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08143FCC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143FD0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143FD2
	.align 2, 0
_08143FCC: .4byte 0x0000046C
_08143FD0:
	movs r0, #0
_08143FD2:
	cmp r0, #0
	beq _08144010
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08144080 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
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
	strh r2, [r0]
_08144010:
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r0, [r0]
	movs r1, #0x28
	cmp r0, #1
	bne _08144020
	movs r1, #0x18
_08144020:
	ldr r2, _08144084 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, r1
	ble _081440DC
	ldr r3, _08144088 @ =0x00000664
	adds r0, r6, r3
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _081440AE
	ldr r0, _0814408C @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _08144094
	ldr r4, _08144090 @ =0xFFFFFF00
	adds r1, r1, r4
	b _081440A2
	.align 2, 0
_08144080: .4byte 0x0000046D
_08144084: .4byte 0x00000484
_08144088: .4byte 0x00000664
_0814408C: .4byte 0x03002BE0
_08144090: .4byte 0xFFFFFF00
_08144094:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081440A2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081440A2:
	adds r0, r1, #0
	cmp r0, #0
	bge _081440AA
	rsbs r0, r0, #0
_081440AA:
	cmp r0, #0x40
	ble _081440DC
_081440AE:
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081440D4 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _081440D8 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	b _08144140
	.align 2, 0
_081440D4: .4byte 0x00000469
_081440D8: .4byte 0x0000046A
_081440DC:
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r6, r1
	add r3, sp, #8
	ldrb r4, [r5, #5]
	ldrb r6, [r0]
	ldr r2, _08144104 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08144108
	asrs r1, r0, #0xc
	b _0814410E
	.align 2, 0
_08144104: .4byte gSineTable
_08144108:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814410E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08144126
	asrs r0, r0, #0xc
	b _0814412C
_08144126:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814412C:
	strh r0, [r3, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r3, _08144148 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08144140:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08144148: .4byte 0x00000484
