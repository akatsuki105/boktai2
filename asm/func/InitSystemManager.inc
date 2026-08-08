	push {r4, r5, r6, lr}
	bl FUN_082308a8
	bl ResetEntityManager
	bl FUN_08230db8
	bl FUN_08230e90
	ldr r1, _08230788 @ =gRNG_0300451c
	ldr r0, _0823078C @ =0x0001E240
	str r0, [r1]
	ldr r4, _08230790 @ =gSystemManager
	ldr r1, _08230794 @ =SystemManager_Update
	adds r0, r4, #0
	movs r2, #0
	bl SetEntityRoutine
	movs r5, #0
	strb r5, [r4, #0x14]
	movs r6, #1
	strb r6, [r4, #0x16]
	strh r5, [r4, #0x10]
	adds r0, r4, #0
	bl AddEntity
	ldr r0, _08230798 @ =0x030044BC
	str r5, [r0]
	ldr r0, _0823079C @ =0x030044C0
	strh r6, [r0]
	ldr r0, _082307A0 @ =0x030044D0
	str r5, [r0]
	ldr r1, _082307A4 @ =0x03004510
	ldr r2, _082307A8 @ =0x000003FF
	adds r0, r1, #6
_0823077A:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0823077A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08230788: .4byte gRNG_0300451c
_0823078C: .4byte 0x0001E240
_08230790: .4byte gSystemManager
_08230794: .4byte SystemManager_Update
_08230798: .4byte 0x030044BC
_0823079C: .4byte 0x030044C0
_082307A0: .4byte 0x030044D0
_082307A4: .4byte 0x03004510
_082307A8: .4byte 0x000003FF
