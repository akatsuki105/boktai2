	push {r4, lr}
	ldr r0, _080A628C @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A629A
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A6298
	ldr r1, _080A6290 @ =EntityCF58_Update
	ldr r2, _080A6294 @ =EntityCF58_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityCF58_Init
	cmp r0, #0
	bge _080A6298
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A629A
	.align 2, 0
_080A628C: .4byte 0x0300014C
_080A6290: .4byte EntityCF58_Update
_080A6294: .4byte EntityCF58_Destroy
_080A6298:
	adds r0, r4, #0
_080A629A:
	pop {r4}
	pop {r1}
	bx r1
