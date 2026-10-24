	push {r4, r5, r6, lr}
	movs r0, #0x6b
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820CF80
	bl VM_GetValue
	adds r6, r0, #0
	b _0820CF82
_0820CF80:
	movs r6, #0
_0820CF82:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820CF94
	bl VM_GetValue
	adds r5, r0, #0
	b _0820CF96
_0820CF94:
	movs r5, #0
_0820CF96:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820CFA8
	bl VM_GetValue
	adds r4, r0, #0
	b _0820CFAA
_0820CFA8:
	movs r4, #0
_0820CFAA:
	adds r0, r6, #0
	adds r1, r5, #0
	bl EnemyDex_GetEntryIdx
	adds r1, r4, #0
	bl EnemyDex_SetFlag
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
