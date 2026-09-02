	push {r4, r5, lr}
	ldr r0, _08002058 @ =gEntity4AE5
	ldr r0, [r0]
	cmp r0, #0
	beq _08002050
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08001f54
_08002050:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08002058: .4byte gEntity4AE5
