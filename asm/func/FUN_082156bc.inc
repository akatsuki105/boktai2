	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08215718 @ =0x00000DB4
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x34
	adds r4, r1, #0
	muls r4, r0, r4
	adds r4, r4, r5
	ldr r0, _0821571C @ =0x000007B4
	adds r4, r4, r0
	ldr r1, _08215720 @ =0x00000DBA
	adds r5, r5, r1
	movs r0, #0
	ldrsh r2, [r5, r0]
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r0, #0x20
	adds r0, r0, r2
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xc
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	bl FUN_082401e8
	ldr r1, _08215724 @ =0x030047E0
	movs r0, #0
	strb r0, [r1, #9]
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r4, #2
	adds r4, r4, r0
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, _08215728 @ =gSystemSaveData
	ldr r0, [r0]
	str r1, [r0, #0x20]
	bl FUN_082410bc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08215718: .4byte 0x00000DB4
_0821571C: .4byte 0x000007B4
_08215720: .4byte 0x00000DBA
_08215724: .4byte 0x030047E0
_08215728: .4byte gSystemSaveData
