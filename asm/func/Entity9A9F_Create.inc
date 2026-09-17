	push {r4, r5, r6, r7, lr}
	ldr r4, _081DFC74 @ =0x03002C68
	ldr r7, [r4]
	cmp r7, #0
	beq _081DFC78
	adds r0, r7, #0
	b _081DFE54
	.align 2, 0
_081DFC74: .4byte 0x03002C68
_081DFC78:
	movs r5, #0xbd
	lsls r5, r5, #2
	adds r0, r5, #0
	bl Malloc
	str r0, [r4]
	cmp r0, #0
	bne _081DFC8A
	b _081DFE28
_081DFC8A:
	adds r6, r0, #0
	adds r1, r5, #0
	bl ClearMemory
	ldr r2, _081DFDC4 @ =Entity9A9F_Destroy
	adds r0, r6, #0
	movs r1, #0
	bl SetEntityRoutine
	movs r4, #1
	strb r4, [r6, #0x14]
	strb r4, [r6, #0x16]
	movs r5, #0
	strh r7, [r6, #0x10]
	adds r0, r6, #0
	bl AddEntity
	ldr r0, _081DFDC8 @ =0x0300481C
	str r4, [r0]
	bl FUN_08238b04
	ldr r0, _081DFDCC @ =0x0000FFFF
	strh r0, [r6, #0x18]
	strb r5, [r6, #0x1e]
	adds r1, r6, #0
	adds r1, #0x6c
	str r1, [r6, #0x44]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r6, #0x48]
	str r0, [r6, #0x4c]
	adds r0, r6, #0
	adds r0, #0x50
	strb r5, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	movs r5, #0
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
	adds r2, r6, #0
	adds r2, #0x68
	movs r3, #0
_081DFCE8:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r0, r2, r5
	strb r3, [r0]
	adds r1, #2
	adds r5, #1
	cmp r5, #3
	ble _081DFCE8
	adds r0, r6, #0
	bl FUN_081de0dc
	adds r0, r6, #0
	bl FUN_081de090
	ldr r2, _081DFDD0 @ =FUN_081de214
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081dd9b8
	adds r1, r6, #0
	adds r1, #0x20
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x55
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DFDD4 @ =0x000002EA
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x59
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DFDD8 @ =0x000002E2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DFDDC @ =0x000002DE
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x76
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x45
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DFDE0 @ =0x000002E6
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #5
	strh r0, [r6, #0x30]
	strh r0, [r6, #0x32]
	ldr r1, _081DFDE4 @ =0x00001388
	movs r0, #0x4c
	bl VM_GetKeywordValue
	str r0, [r6, #0x3c]
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DFDE8
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #3
_081DFDB4:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _081DFDB4
	b _081DFE0E
	.align 2, 0
_081DFDC4: .4byte Entity9A9F_Destroy
_081DFDC8: .4byte 0x0300481C
_081DFDCC: .4byte 0x0000FFFF
_081DFDD0: .4byte FUN_081de214
_081DFDD4: .4byte 0x000002EA
_081DFDD8: .4byte 0x000002E2
_081DFDDC: .4byte 0x000002DE
_081DFDE0: .4byte 0x000002E6
_081DFDE4: .4byte 0x00001388
_081DFDE8:
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xab
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, #4
	adds r1, r6, r2
	ldr r0, _081DFE2C @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081DFE30 @ =0x0000FFFE
	strh r0, [r1]
_081DFE0E:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DFE28
	bl FUN_0823d340
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DFE34
_081DFE28:
	movs r0, #0
	b _081DFE54
	.align 2, 0
_081DFE2C: .4byte 0x0000FFFF
_081DFE30: .4byte 0x0000FFFE
_081DFE34:
	movs r0, #0x53
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DFE28
	bl FUN_0823d340
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	beq _081DFE28
	movs r0, #7
	bl FUN_0809c08c
_081DFE54:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
