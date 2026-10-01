	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [r5, #0x34]
	cmp r0, #0
	bne _08000AAA
	movs r1, #0x94
	lsls r1, r1, #1
	movs r0, #9
	b _08000AB0
_08000AAA:
	movs r1, #0x94
	lsls r1, r1, #1
	movs r0, #0xb
_08000AB0:
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08000AE4
	ldr r1, _08000ADC @ =Video_GenerateBackgroundMaps
	ldr r2, _08000AE0 @ =Entity08000a94_Destroy
	adds r0, r4, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl Entity08000a94_Init
	cmp r0, #0
	bge _08000AE4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08000AE6
	.align 2, 0
_08000ADC: .4byte Video_GenerateBackgroundMaps
_08000AE0: .4byte Entity08000a94_Destroy
_08000AE4:
	adds r0, r4, #0
_08000AE6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
