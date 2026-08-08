	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _08062990 @ =0x00000951
	adds r0, r5, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _0806290E
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08062468
_0806290E:
	adds r0, r5, #0
	bl FUN_0806241c
	adds r2, r0, #0
	ldr r6, _08062994 @ =0x0000094C
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne _0806292C
	adds r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _0806293A
_0806292C:
	strh r4, [r1]
	ldr r1, _08062998 @ =0x0000094E
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_080622d0
_0806293A:
	ldr r2, _0806299C @ =0x0000096C
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _08062A1C
	ldr r3, _080629A0 @ =0x00000964
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r6, #0x96
	lsls r6, r6, #4
	adds r4, r5, r6
	ldrh r0, [r4]
	cmp r0, #0x1f
	bls _080629EC
	ldr r1, _080629A4 @ =0x03003584
	subs r2, #0xe
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _080629A8 @ =0x00000359
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080629C6
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_08062980:
	subs r0, r3, #5
	cmp r0, #1
	bls _0806298A
	cmp r3, #0xd
	bne _080629AC
_0806298A:
	ldrh r0, [r4]
	b _080629AE
	.align 2, 0
_08062990: .4byte 0x00000951
_08062994: .4byte 0x0000094C
_08062998: .4byte 0x0000094E
_0806299C: .4byte 0x0000096C
_080629A0: .4byte 0x00000964
_080629A4: .4byte 0x03003584
_080629A8: .4byte 0x00000359
_080629AC:
	ldrh r0, [r1]
_080629AE:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08062980
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _08062C0C
_080629C6:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_080629CE:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _080629CE
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	b _08062C0A
_080629EC:
	ldr r1, _08062A14 @ =0x03003584
	ldr r3, _08062A18 @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r4]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080624b0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08062C0C
	.align 2, 0
_08062A14: .4byte 0x03003584
_08062A18: .4byte 0x0000095E
_08062A1C:
	cmp r0, #2
	bne _08062A96
	ldr r6, _08062A48 @ =0x00000964
	adds r1, r5, r6
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08062A4C @ =0x03003584
	ldr r2, _08062A50 @ =0x0000095E
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r4, r1, r0
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _08062A54
	adds r2, r1, #0
	b _08062A6A
	.align 2, 0
_08062A48: .4byte 0x00000964
_08062A4C: .4byte 0x03003584
_08062A50: .4byte 0x0000095E
_08062A54:
	cmp r1, #0x2f
	bhi _08062A5C
	movs r2, #0x20
	b _08062A6A
_08062A5C:
	cmp r1, #0x4f
	bhi _08062A68
	ldrh r1, [r0]
	movs r0, #0x50
	subs r2, r0, r1
	b _08062A6A
_08062A68:
	movs r2, #0
_08062A6A:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080624b0
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _08062A90
	b _08062C0C
_08062A90:
	movs r0, #0
	strh r0, [r1]
	b _08062C0C
_08062A96:
	movs r0, #0x96
	lsls r0, r0, #4
	adds r2, r5, r0
	ldrh r4, [r2]
	cmp r4, #0
	beq _08062B70
	ldr r1, _08062AE8 @ =0x00000964
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _08062B3A
	ldr r1, _08062AEC @ =0x03003584
	ldr r2, _08062AF0 @ =0x0000095E
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _08062AF4 @ =0x00000359
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08062B12
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_08062AD8:
	subs r0, r3, #5
	cmp r0, #1
	bls _08062AE2
	cmp r3, #0xd
	bne _08062AF8
_08062AE2:
	ldrh r0, [r4]
	b _08062AFA
	.align 2, 0
_08062AE8: .4byte 0x00000964
_08062AEC: .4byte 0x03003584
_08062AF0: .4byte 0x0000095E
_08062AF4: .4byte 0x00000359
_08062AF8:
	ldrh r0, [r1]
_08062AFA:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08062AD8
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _08062B58
_08062B12:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_08062B1A:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08062B1A
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _08062B58
_08062B3A:
	ldr r1, _08062B68 @ =0x03003584
	ldr r3, _08062B6C @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080624b0
_08062B58:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _08062C0C
	.align 2, 0
_08062B68: .4byte 0x03003584
_08062B6C: .4byte 0x0000095E
_08062B70:
	ldr r0, _08062BAC @ =0x00000964
	adds r3, r5, r0
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _08062BDE
	ldr r1, _08062BB0 @ =0x03003584
	ldr r6, _08062BB4 @ =0x00000962
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _08062B9E
	movs r0, #0x30
	strh r0, [r3]
_08062B9E:
	ldrh r0, [r3]
	cmp r0, #0x20
	bhi _08062BB8
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _08062BCC
	.align 2, 0
_08062BAC: .4byte 0x00000964
_08062BB0: .4byte 0x03003584
_08062BB4: .4byte 0x00000962
_08062BB8:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _08062BCC
	strh r4, [r3]
_08062BCC:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080624b0
	b _08062C0C
_08062BDE:
	strh r4, [r3]
	ldr r1, _08062BF8 @ =0x00000359
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08062BFC
	adds r1, r5, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
	b _08062C0C
	.align 2, 0
_08062BF8: .4byte 0x00000359
_08062BFC:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r6, #0xa9
	lsls r6, r6, #2
	adds r0, r5, r6
_08062C0A:
	str r0, [r1, #0xc]
_08062C0C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
