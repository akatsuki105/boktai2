	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	mov r8, r1
	adds r4, r2, #0
	ldr r0, _08196024 @ =0x00000C38
	adds r6, r4, r0
	ldr r0, [r6]
	ldr r1, _08196028 @ =EneSword_StateDying
	mov sb, r1
	cmp r0, sb
	bne _08195FFC
	b _08196342
_08195FFC:
	ldr r2, _0819602C @ =0x00000C28
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08196034
	ldr r3, _08196030 @ =0x00000CE6
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08196012
	b _08196342
_08196012:
	movs r0, #0
	movs r1, #0
	mov r2, r8
	strh r1, [r2, #0x3e]
	mov r1, r8
	adds r1, #0x43
	strb r0, [r1]
	b _08196342
	.align 2, 0
_08196024: .4byte 0x00000C38
_08196028: .4byte EneSword_StateDying
_0819602C: .4byte 0x00000C28
_08196030: .4byte 0x00000CE6
_08196034:
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamage
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	ldr r3, _081960F4 @ =0x00000C5C
	adds r2, r4, r3
	ldr r5, [r2]
	movs r0, #0x4b
	adds r0, r0, r4
	mov sl, r0
	cmp r5, #0
	beq _0819605A
	b _081962F6
_0819605A:
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	bne _08196064
	b _0819630C
_08196064:
	ldr r1, [r7, #0x34]
	adds r3, #0x74
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, [r7, #0x38]
	adds r3, #4
	adds r0, r4, r3
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #8
	strh r0, [r1]
	ldr r0, _081960F8 @ =EneSword_UpdateFlash
	str r0, [r2]
	ldr r1, _081960FC @ =0x00000AEC
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r2, _08196100 @ =0x00000CC8
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	ldrh r1, [r4, #0x36]
	mov r3, r8
	ldrh r0, [r3, #0x3e]
	subs r1, r1, r0
	strh r1, [r4, #0x36]
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _081960A6
	ldrh r0, [r3, #0x3e]
	adds r0, r0, r1
	strh r0, [r3, #0x3e]
_081960A6:
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	ldrh r2, [r7, #0x3e]
	adds r0, r0, r2
	strh r0, [r7, #0x3e]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	cmp r0, #0
	ble _081960BA
	b _081962F6
_081960BA:
	strh r5, [r4, #0x36]
	movs r0, #1
	movs r1, #6
	adds r2, r4, #0
	adds r2, #0x4a
	strb r0, [r2]
	mov r2, sl
	strb r1, [r2]
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	mov r3, sb
	str r3, [r6]
	ldr r2, _08196104 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldrh r6, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _08196108 @ =0x0000270E
	adds r5, r2, #0
	cmp r1, r0
	bgt _0819610C
	adds r0, r6, #1
	b _08196110
	.align 2, 0
_081960F4: .4byte 0x00000C5C
_081960F8: .4byte EneSword_UpdateFlash
_081960FC: .4byte 0x00000AEC
_08196100: .4byte 0x00000CC8
_08196104: .4byte 0x030046A0
_08196108: .4byte 0x0000270E
_0819610C:
	ldr r1, _08196130 @ =0x0000270F
	adds r0, r1, #0
_08196110:
	strh r0, [r3]
	ldr r2, _08196134 @ =0x00000C1C
	adds r0, r4, r2
	ldr r2, [r0]
	ldr r0, [r5]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrh r6, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _08196138 @ =0x0000270E
	cmp r1, r0
	bgt _0819613C
	adds r0, r6, #1
	b _08196140
	.align 2, 0
_08196130: .4byte 0x0000270F
_08196134: .4byte 0x00000C1C
_08196138: .4byte 0x0000270E
_0819613C:
	ldr r1, _08196164 @ =0x0000270F
	adds r0, r1, #0
_08196140:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08196176
	ldr r0, [r5]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #1
	ldr r0, _08196164 @ =0x0000270F
	cmp r1, r0
	ble _08196168
	adds r1, r0, #0
	b _0819616E
	.align 2, 0
_08196164: .4byte 0x0000270F
_08196168:
	cmp r1, #0
	bge _0819616E
	movs r1, #0
_0819616E:
	ldr r0, [r5]
	movs r2, #0x8a
	lsls r2, r2, #2
	b _08196254
_08196176:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081961B0
	ldr r0, [r5]
	ldr r3, _08196198 @ =0x0000022A
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _0819619C @ =0x0000270F
	cmp r1, r0
	ble _081961A0
	adds r1, r0, #0
	b _081961A6
	.align 2, 0
_08196198: .4byte 0x0000022A
_0819619C: .4byte 0x0000270F
_081961A0:
	cmp r1, #0
	bge _081961A6
	movs r1, #0
_081961A6:
	ldr r0, [r5]
	ldr r2, _081961AC @ =0x0000022A
	b _08196254
	.align 2, 0
_081961AC: .4byte 0x0000022A
_081961B0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081961E6
	ldr r0, [r5]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _081961D4 @ =0x0000270F
	cmp r1, r0
	ble _081961D8
	adds r1, r0, #0
	b _081961DE
	.align 2, 0
_081961D4: .4byte 0x0000270F
_081961D8:
	cmp r1, #0
	bge _081961DE
	movs r1, #0
_081961DE:
	ldr r0, [r5]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _08196254
_081961E6:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r2
	cmp r0, #0
	beq _08196220
	ldr r0, [r5]
	ldr r3, _08196208 @ =0x0000022E
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _0819620C @ =0x0000270F
	cmp r1, r0
	ble _08196210
	adds r1, r0, #0
	b _08196216
	.align 2, 0
_08196208: .4byte 0x0000022E
_0819620C: .4byte 0x0000270F
_08196210:
	cmp r1, #0
	bge _08196216
	movs r1, #0
_08196216:
	ldr r0, [r5]
	ldr r2, _0819621C @ =0x0000022E
	b _08196254
	.align 2, 0
_0819621C: .4byte 0x0000022E
_08196220:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r2, r0
	cmp r2, #0
	beq _08196258
	ldr r0, [r5]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _08196244 @ =0x0000270F
	cmp r1, r0
	ble _08196248
	adds r1, r0, #0
	b _0819624E
	.align 2, 0
_08196244: .4byte 0x0000270F
_08196248:
	cmp r1, #0
	bge _0819624E
	movs r1, #0
_0819624E:
	ldr r0, [r5]
	movs r2, #0x8c
	lsls r2, r2, #2
_08196254:
	adds r0, r0, r2
	strh r1, [r0]
_08196258:
	ldrh r0, [r7, #0xa]
	cmp r0, #2
	beq _08196290
	cmp r0, #2
	bgt _08196268
	cmp r0, #1
	beq _08196272
	b _081962F6
_08196268:
	cmp r0, #4
	beq _081962B0
	cmp r0, #8
	beq _081962D0
	b _081962F6
_08196272:
	ldr r0, [r5]
	ldr r3, _08196288 @ =0x00000948
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0819628C @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_08196288: .4byte 0x00000948
_0819628C: .4byte 0x0000270E
_08196290:
	ldr r0, [r5]
	ldr r3, _081962A8 @ =0x0000094A
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081962AC @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_081962A8: .4byte 0x0000094A
_081962AC: .4byte 0x0000270E
_081962B0:
	ldr r0, [r5]
	ldr r3, _081962C8 @ =0x0000094C
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081962CC @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_081962C8: .4byte 0x0000094C
_081962CC: .4byte 0x0000270E
_081962D0:
	ldr r0, [r5]
	ldr r3, _081962E8 @ =0x0000094E
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081962EC @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_081962E8: .4byte 0x0000094E
_081962EC: .4byte 0x0000270E
_081962F0:
	ldr r1, _08196308 @ =0x0000270F
	adds r0, r1, #0
_081962F4:
	strh r0, [r2]
_081962F6:
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	cmp r0, #0
	beq _0819630C
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08196314
	.align 2, 0
_08196308: .4byte 0x0000270F
_0819630C:
	movs r0, #0xc8
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08196314:
	mov r3, sl
	ldrb r0, [r3]
	cmp r0, #1
	bne _0819632C
	ldrh r0, [r4, #0x1c]
	rsbs r0, r0, #0
	lsls r0, r0, #2
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #0x20]
	rsbs r0, r0, #0
	lsls r0, r0, #2
	strh r0, [r4, #0x30]
_0819632C:
	mov r0, r8
	ldrh r1, [r0, #0x3e]
	ldr r2, _08196350 @ =0x00000CE4
	adds r0, r4, r2
	strh r1, [r0]
	mov r0, r8
	adds r0, #0x43
	ldrb r1, [r0]
	ldr r3, _08196354 @ =0x00000CE6
	adds r0, r4, r3
	strh r1, [r0]
_08196342:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196350: .4byte 0x00000CE4
_08196354: .4byte 0x00000CE6
