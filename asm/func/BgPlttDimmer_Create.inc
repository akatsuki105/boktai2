	push {r4, lr}
	movs r0, #9
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B350
	ldr r1, _0801B348 @ =BgPlttDimmer_Update
	ldr r2, _0801B34C @ =BgPlttDimmer_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl BgPlttDimmer_Init
	cmp r0, #0
	bge _0801B350
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B352
	.align 2, 0
_0801B348: .4byte BgPlttDimmer_Update
_0801B34C: .4byte BgPlttDimmer_Destroy
_0801B350:
	adds r0, r4, #0
_0801B352:
	pop {r4}
	pop {r1}
	bx r1
