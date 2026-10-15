	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xf8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A19AC
	ldr r1, _080A19A4 @ =AlarmPanel_Update
	ldr r2, _080A19A8 @ =AlarmPanel_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl AlarmPanel_Init
	cmp r0, #0
	bge _080A19AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A19AE
	.align 2, 0
_080A19A4: .4byte AlarmPanel_Update
_080A19A8: .4byte AlarmPanel_Destroy
_080A19AC:
	adds r0, r4, #0
_080A19AE:
	pop {r4, r5}
	pop {r1}
	bx r1
