	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start EntityA687_Update
EntityA687_Update: @ 0x0801B20C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	cmp r0, #1
	beq _0801B234
	cmp r0, #1
	blo _0801B220
	cmp r0, #2
	beq _0801B24A
	b _0801B268
_0801B220:
	ldr r2, [r4, #0x24]
	ldr r1, [r4, #0x1c]
	cmp r2, r1
	bls _0801B22E
	subs r0, r2, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B22E:
	str r1, [r4, #0x24]
	adds r0, #1
	b _0801B242
_0801B234:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x20]
	cmp r0, r1
	blo _0801B268
	movs r0, #2
_0801B242:
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	b _0801B268
_0801B24A:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3f
	bhi _0801B256
	adds r0, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B256:
	movs r0, #0x40
	str r0, [r4, #0x24]
	movs r0, #3
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl KillEntity
_0801B268:
	ldr r0, _0801B294 @ =0x03004460
	ldr r3, [r4, #0x24]
	str r3, [r0]
	ldr r1, _0801B298 @ =0x03004454
	ldr r2, _0801B29C @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2A0 @ =0x03004494
	ldr r1, _0801B2A4 @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2A8 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2AC @ =0x03004490
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _0801B2B0 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B294: .4byte 0x03004460
_0801B298: .4byte 0x03004454
_0801B29C: .4byte 0x00001FFF
_0801B2A0: .4byte 0x03004494
_0801B2A4: .4byte 0x00001084
_0801B2A8: .4byte 0x0300445C
_0801B2AC: .4byte 0x03004490
_0801B2B0: .4byte 0x03004464

	thumb_func_start EntityA687_Destroy
EntityA687_Destroy: @ 0x0801B2B4
	ldr r0, _0801B2DC @ =0x03004460
	movs r3, #0x40
	str r3, [r0]
	ldr r1, _0801B2E0 @ =0x03004454
	ldr r2, _0801B2E4 @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2E8 @ =0x03004494
	ldr r1, _0801B2EC @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2F0 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2F4 @ =0x03004490
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801B2F8 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_0801B2DC: .4byte 0x03004460
_0801B2E0: .4byte 0x03004454
_0801B2E4: .4byte 0x00001FFF
_0801B2E8: .4byte 0x03004494
_0801B2EC: .4byte 0x00001084
_0801B2F0: .4byte 0x0300445C
_0801B2F4: .4byte 0x03004490
_0801B2F8: .4byte 0x03004464

	thumb_func_start EntityA687_Init
EntityA687_Init: @ 0x0801B2FC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	movs r1, #0x20
	bl VM_GetKeywordValue
	str r0, [r4, #0x1c]
	movs r0, #0x65
	movs r1, #0x78
	bl VM_GetKeywordValue
	str r0, [r4, #0x20]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityA687_Create
EntityA687_Create: @ 0x0801B31C
	push {r4, lr}
	movs r0, #9
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B350
	ldr r1, _0801B348 @ =EntityA687_Update
	ldr r2, _0801B34C @ =EntityA687_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityA687_Init
	cmp r0, #0
	bge _0801B350
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B352
	.align 2, 0
_0801B348: .4byte EntityA687_Update
_0801B34C: .4byte EntityA687_Destroy
_0801B350:
	adds r0, r4, #0
_0801B352:
	pop {r4}
	pop {r1}
	bx r1
