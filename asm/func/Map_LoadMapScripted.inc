	push {r4, r5, r6, r7, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r0, #0x68
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x7a
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0823B620
	bl Map_LoadCollisionMapFile
	b _0823B650
_0823B620:
	cmp r4, #0
	beq _0823B62C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl FUN_082327c0
_0823B62C:
	cmp r5, #0
	beq _0823B638
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl FUN_082345f8
_0823B638:
	cmp r6, #0
	beq _0823B644
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08234db8
_0823B644:
	cmp r7, #0
	beq _0823B650
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	bl FUN_082358f4
_0823B650:
	ldr r0, _0823B688 @ =0x000056C2
	bl FUN_08230e70
	ldr r4, [r0, #4]
	movs r0, #0x76
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823B6AE
	bl Script_GetValue
	cmp r0, #0
	bne _0823B69C
	ldr r1, _0823B68C @ =FUN_0822db5c
	ldr r2, _0823B690 @ =FUN_0822aaac
	ldr r3, _0823B694 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	ldr r1, _0823B698 @ =0x03003540
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r1, #8]
	ldrh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	b _0823B6AC
	.align 2, 0
_0823B688: .4byte 0x000056C2
_0823B68C: .4byte FUN_0822db5c
_0823B690: .4byte FUN_0822aaac
_0823B694: .4byte FUN_0822f204
_0823B698: .4byte 0x03003540
_0823B69C:
	ldr r1, _0823B6B4 @ =FUN_0822de64
	ldr r2, _0823B6B8 @ =FUN_0822ac90
	ldr r3, _0823B6BC @ =FUN_0822f224
	bl FUN_0822a448
	ldr r1, _0823B6C0 @ =0x03003540
	movs r0, #0
	strh r0, [r1, #8]
_0823B6AC:
	strh r0, [r1, #0xa]
_0823B6AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823B6B4: .4byte FUN_0822de64
_0823B6B8: .4byte FUN_0822ac90
_0823B6BC: .4byte FUN_0822f224
_0823B6C0: .4byte 0x03003540
