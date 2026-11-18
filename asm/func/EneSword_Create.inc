	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r1, _0819AA40 @ =0x00000CF4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0819AA50
	ldr r1, _0819AA44 @ =0x00000CE8
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _0819AA48 @ =EneSword_Update
	ldr r2, _0819AA4C @ =EneSword_Destroy
	adds r0, r4, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EneSword_Init
	cmp r0, #0
	bge _0819AA50
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0819AA52
	.align 2, 0
_0819AA40: .4byte 0x00000CF4
_0819AA44: .4byte 0x00000CE8
_0819AA48: .4byte EneSword_Update
_0819AA4C: .4byte EneSword_Destroy
_0819AA50:
	adds r0, r4, #0
_0819AA52:
	pop {r4, r5}
	pop {r1}
	bx r1
