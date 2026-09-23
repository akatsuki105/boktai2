	push {r4, lr}
	movs r1, #0x88
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B65C
	ldr r1, _0801B654 @ =BgPlttAnimator_Update
	ldr r2, _0801B658 @ =BgPlttAnimator_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl BgPlttAnimator_Init
	cmp r0, #0
	bge _0801B65C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B65E
	.align 2, 0
_0801B654: .4byte BgPlttAnimator_Update
_0801B658: .4byte BgPlttAnimator_Destroy
_0801B65C:
	adds r0, r4, #0
_0801B65E:
	pop {r4}
	pop {r1}
	bx r1
