	push {r4, lr}
	ldr r0, _080DDB08 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DDB16
	movs r1, #0x84
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DDB14
	ldr r1, _080DDB0C @ =AttackBoxManager_Update
	ldr r2, _080DDB10 @ =AttackBoxManager_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl AttackBoxManager_Init
	cmp r0, #0
	bge _080DDB14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DDB16
	.align 2, 0
_080DDB08: .4byte 0x03000170
_080DDB0C: .4byte AttackBoxManager_Update
_080DDB10: .4byte AttackBoxManager_Destroy
_080DDB14:
	adds r0, r4, #0
_080DDB16:
	pop {r4}
	pop {r1}
	bx r1
