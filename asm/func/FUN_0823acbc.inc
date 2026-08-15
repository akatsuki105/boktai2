	push {r4, r5, lr}
	bl FUN_0823b158
	bl FUN_0823aa84
	bl FUN_0823b130
	bl FUN_082324b0
	ldr r0, _0823AD48 @ =0x030047A4
	movs r5, #0
	str r5, [r0]
	ldr r0, _0823AD4C @ =0x030047A0
	str r5, [r0]
	ldr r0, _0823AD50 @ =0x0300479C
	str r5, [r0]
	ldr r0, _0823AD54 @ =0x030047C0
	str r5, [r0]
	ldr r1, _0823AD58 @ =0x03004798
	ldr r0, _0823AD5C @ =0x0300478C
	str r5, [r0]
	ldr r0, _0823AD60 @ =0x030047C4
	str r5, [r0]
	ldr r0, _0823AD64 @ =0x030047B8
	str r5, [r0]
	ldr r0, _0823AD68 @ =0x030047B0
	str r5, [r0]
	ldr r0, _0823AD6C @ =0x03004790
	str r5, [r0]
	ldr r0, _0823AD70 @ =0x030047BC
	str r5, [r0]
	ldr r0, _0823AD74 @ =0x03004794
	str r5, [r0]
	ldr r0, _0823AD78 @ =0x030047AC
	str r5, [r0]
	ldr r0, _0823AD7C @ =0x03004788
	str r5, [r0]
	ldr r4, _0823AD80 @ =0x030046A0
	ldr r0, [r4]
	ldr r2, _0823AD84 @ =0x00000934
	adds r0, r0, r2
	strh r5, [r0]
	str r5, [r1]
	ldr r0, _0823AD88 @ =0x03004860
	str r5, [r0]
	bl FUN_0823d280
	bl CreateRandomTable
	movs r1, #2
	ldr r0, [r4]
	strh r1, [r0, #0x12]
	ldr r4, _0823AD8C @ =0x030016A0
	ldr r1, _0823AD90 @ =Entity1_030016a0_Update
	ldr r2, _0823AD94 @ =Entity1_030016a0_Destroy
	adds r0, r4, #0
	bl SetEntityRoutine
	movs r0, #1
	strb r0, [r4, #0x14]
	strb r0, [r4, #0x16]
	strh r5, [r4, #0x10]
	adds r0, r4, #0
	bl AddEntity
	str r5, [r4, #0x18]
	str r5, [r4, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823AD48: .4byte 0x030047A4
_0823AD4C: .4byte 0x030047A0
_0823AD50: .4byte 0x0300479C
_0823AD54: .4byte 0x030047C0
_0823AD58: .4byte 0x03004798
_0823AD5C: .4byte 0x0300478C
_0823AD60: .4byte 0x030047C4
_0823AD64: .4byte 0x030047B8
_0823AD68: .4byte 0x030047B0
_0823AD6C: .4byte 0x03004790
_0823AD70: .4byte 0x030047BC
_0823AD74: .4byte 0x03004794
_0823AD78: .4byte 0x030047AC
_0823AD7C: .4byte 0x03004788
_0823AD80: .4byte 0x030046A0
_0823AD84: .4byte 0x00000934
_0823AD88: .4byte 0x03004860
_0823AD8C: .4byte 0x030016A0
_0823AD90: .4byte Entity1_030016a0_Update
_0823AD94: .4byte Entity1_030016a0_Destroy
