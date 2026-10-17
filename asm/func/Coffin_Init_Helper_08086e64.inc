	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08086E9C
	bl VM_GetValue
	movs r2, #0xea
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	bl VM_GetValue
	ldr r3, _08086E98 @ =0x000003AA
	adds r1, r4, r3
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _08086EB0
	.align 2, 0
_08086E98: .4byte 0x000003AA
_08086E9C:
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r2, _08086ECC @ =0x000003AA
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
_08086EB0:
	movs r0, #0x4f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08086ED0
	bl VM_GetValue
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _08086ED8
	.align 2, 0
_08086ECC: .4byte 0x000003AA
_08086ED0:
	movs r3, #0xec
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
_08086ED8:
	ldr r1, _08086F18 @ =0x085ABFF8
	ldrb r0, [r4, #0x1a]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	ldr r2, _08086F1C @ =0x000003A6
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldrb r0, [r4, #0x1a]
	cmp r0, #2
	bne _08086F28
	ldr r0, _08086F20 @ =0x000003A2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08086F24 @ =0x000001F5
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086F46
	movs r0, #0
	strb r0, [r1]
	b _08086F46
	.align 2, 0
_08086F18: .4byte 0x085ABFF8
_08086F1C: .4byte 0x000003A6
_08086F20: .4byte 0x000003A2
_08086F24: .4byte 0x000001F5
_08086F28:
	ldr r3, _08086F7C @ =0x000003A2
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08086F80 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086F46
	adds r0, r4, #0
	bl FUN_080860cc
_08086F46:
	ldr r1, _08086F84 @ =0x085ABFF8
	ldrb r0, [r4, #0x1a]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _08086F88 @ =0x00000392
	adds r1, r4, r2
	movs r2, #0
	strh r0, [r1]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, _08086F8C @ =0x0000039A
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086F7C: .4byte 0x000003A2
_08086F80: .4byte 0x000001F5
_08086F84: .4byte 0x085ABFF8
_08086F88: .4byte 0x00000392
_08086F8C: .4byte 0x0000039A
