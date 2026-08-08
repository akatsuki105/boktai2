	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r1, _08065EDC @ =0x00000397
	adds r0, r6, r1
	movs r2, #0
	movs r3, #1
	mov sb, r3
	mov r1, sb
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0
	mov r8, r0
	movs r0, #0x32
	strh r0, [r1]
	ldr r1, _08065EE0 @ =0x000003D2
	adds r0, r6, r1
	mov r3, r8
	strb r3, [r0]
	adds r1, #0x24
	adds r0, r6, r1
	strh r2, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r7, r6, r2
	ldrh r0, [r7]
	ldr r5, _08065EE4 @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r3, #4
	ldrsh r1, [r1, r3]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r7]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Div
	adds r1, r0, #0
	lsls r4, r4, #8
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r2, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, #0x80
	subs r4, r4, r0
	lsls r1, r1, #8
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r0, #0x80
	subs r1, r1, r0
	adds r0, r4, #0
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, #1
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r1, #4
	bls _08065EF0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08065EE8 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08065EEC @ =0x000002E7
	adds r0, r6, r3
	mov r1, sb
	b _08065EFE
	.align 2, 0
_08065EDC: .4byte 0x00000397
_08065EE0: .4byte 0x000003D2
_08065EE4: .4byte 0x030046A4
_08065EE8: .4byte 0x000002E6
_08065EEC: .4byte 0x000002E7
_08065EF0:
	lsrs r0, r0, #0x19
	ldr r2, _08065F20 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08065F24 @ =0x000002E7
	adds r0, r6, r3
	mov r1, r8
_08065EFE:
	strb r1, [r0]
	ldr r2, _08065F28 @ =0x000003D6
	adds r1, r6, r2
	movs r2, #0
	ldr r0, _08065F2C @ =0x00000191
	strh r0, [r1]
	ldr r3, _08065F30 @ =0x00000396
	adds r0, r6, r3
	strb r2, [r0]
	movs r0, #0xa
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08065F20: .4byte 0x000002E6
_08065F24: .4byte 0x000002E7
_08065F28: .4byte 0x000003D6
_08065F2C: .4byte 0x00000191
_08065F30: .4byte 0x00000396
